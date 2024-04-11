from math import*

def main():
    R=lambda:map(int,input().split())
    k=dict(B=0,S=0,C=0)
    for c in input():
        k[c]+=1
    k=[k['B'],k['S'],k['C']]
    n,p=list(R()),list(R())
    r=int(input())
    ans=0
    for i in range(3):
        if k[i]==0:
            n[i]=0
    while n[0] or n[1] or n[2]:
        t=[k[i]-n[i] if k[i]-n[i]>=0 else 0 for i in range(3)]
        s=sum([t[i]*p[i] for i in range(3)])
        if s>r:
            print(ans)
            return
        r-=s
        for i in range(3):
            n[i]-=k[i]
            if n[i]<0:
                n[i]=0
        ans+=1
    s=sum([k[i]*p[i] for i in range(3)])
    ans+=r//s
    print(ans)

main()