def main():
    n=int(input())
    p=[0,None]+list(map(int,input().split()))
    s=[None]+list(map(int,input().split()))
    a=[None,s[1]]+[None]*(n-1)
    children=[0]
    for i in range(n):
        children.append([])
    for i in range(2,n+1):
        children[p[i]].append(i)
    broken=[False]
    def dostuff(parent,children,vals):
        small=vals[parent]
        for child in children[parent]:
            if len(children[child])>0:
                mini=min(s[guy] for guy in children[child])
            else:
                mini=small
            if mini<small:
                broken[0]=True
            a[child]=mini-small
            for child1 in children[child]:
                a[child1]=s[child1]-mini
                dostuff(child1,children,vals)
    dostuff(1,children,s)
    if broken[0]:
        print(-1)
    else:
        print(sum(a[1:]))

import sys
import threading
sys.setrecursionlimit(2097152)
threading.stack_size(134217728)
main_thread=threading.Thread(target=main)
main_thread.start()
main_thread.join()