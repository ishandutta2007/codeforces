from __future__ import division
def main():
    t=int(raw_input())
    for u in xrange(t):
        n,m=map(int,raw_input().split())
        if n==1:
            print(3)
        elif n==2 and m==1:
            raw_input()
            print(4)
        else:
            neigh=[]
            for i in xrange(n):
                neigh.append([])
            for i in xrange(m):
                a,b=map(int,raw_input().split())
                neigh[a-1].append(b-1)
                neigh[b-1].append(a-1)
            groups=[0]*n
            count=0
            done=False
            for i in xrange(n):
                if done:
                    break
                if groups[i]==0:
                    count+=2
                    groups[i]=count-1
                    level=[i]
                    prev={}
                    levelcount=0
                    while True:
                        if done or level==[]:
                            break
                        levelcount+=1
                        levelcount%=2
                        newlevel=[]
                        for guy in level:
                            for vert in neigh[guy]:
                                if vert not in prev:
                                    if groups[vert]==count-levelcount:
                                        done=True
                                        break
                                    elif groups[vert]==0:
                                        groups[vert]=count-(levelcount-1)%2
                                        newlevel.append(vert)
                        prev=set(level)
                        level=list(set(newlevel))
            if done:
                print(0)
            else:
                counts=[0]*count
                for i in xrange(n):
                    counts[groups[i]-1]+=1
                prod=1
                for i in xrange(count//2):
                    new=(2**counts[2*i])%998244353+(2**counts[2*i+1])%998244353
                    prod*=new
                    prod%=998244353
                print(prod)
main()