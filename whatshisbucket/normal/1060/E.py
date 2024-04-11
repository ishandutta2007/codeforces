def main():
    def countchildren(graph,vert,memo,pard=None):
        dumi=0
        for child in graph[vert]:
            if child!=pard:
                if len(graph[child])==1:
                    memo[child]=0
                else:
                    memo[child]=countchildren(graph,child,memo,vert)[0]
                dumi+=memo[child]+1
        return((dumi,memo))
    n=int(input())
    neigh=[]
    for i in range(n):
        neigh.append([])
    for i in range(n-1):
        a,b=map(int,input().split())
        neigh[a-1].append(b-1)
        neigh[b-1].append(a-1)
    same=1
    layer=[0]
    pars=[None]
    j=0
    while layer!=[]:
        j+=1
        newlayer=[]
        newpars=[]
        for i in range(len(layer)):
            for vert in neigh[layer[i]]:
                if vert!=pars[i]:
                    newlayer.append(vert)
                    newpars.append(layer[i])
        layer=newlayer
        pars=newpars
        if j%2==0:
            same+=len(layer)
    bipartite=same*(n-same)
    info=countchildren(neigh,0,[None]*n)[1]
    dist=0
    for guy in info:
        if guy!=None:
           dist+=(guy+1)*(n-guy-1)
    print((dist+bipartite)//2)

import sys
import threading
sys.setrecursionlimit(2097152)
threading.stack_size(134217728)
main_thread=threading.Thread(target=main)
main_thread.start()
main_thread.join()