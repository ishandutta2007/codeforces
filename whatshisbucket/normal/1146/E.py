n,q=map(int,input().split())
a=list(map(int,input().split()))
swaps=[0]*q
for i in range(q):
    b=input().split()
    b[1]=int(b[1])
    out=1 if (b[0]=="<" and b[1]<=0) or (b[0]==">" and b[1]>=0) else 0
    split=b[1]+0.5 if b[0]==">" else b[1]-0.5
    sign=1 if split>0 else -1
    split=abs(split)
    swaps[i]=(split,sign,out)
sml=10**5+0.5
zeros=0
for i in range(q):
    sml=min(swaps[i][0],sml)
    zeros+=1-swaps[i][2]
zeros%=2
arr=[0]*100001
big=100000.5
flips=1
for i in range(q):
    if swaps[-1-i][0]<big:
        if swaps[-1-i][2]==1:
            for j in range(int(swaps[-1-i][0]+0.5),int(big+0.5)):
                arr[j]=-swaps[-i-1][1]*flips
        else:
            for j in range(int(swaps[-1-i][0]+0.5),int(big+0.5)):
                arr[j]=swaps[-i-1][1]*flips
        big=swaps[-1-i][0]
    if swaps[-1-i][2]==0:
        flips=-flips
def func(k):
    if abs(k)<sml:
        return k if zeros==0 else -k
    else:
        return arr[abs(k)]*abs(k)
print(" ".join([str(func(guy)) for guy in a]))