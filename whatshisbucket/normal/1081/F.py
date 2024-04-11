n,t=map(int,input().split())
real=[]
prev=t
flips=0
ones=0
for i in range(1,n):
    reps=0
    while True:
        reps+=1
        print("?",i+1,n)
        u=int(input())
        print("?",i+1,n)
        v=int(input())
        if v!=prev:
            break
        if reps>30:
            break
    if reps==31:
        z=i//2
        if ones==z:
            real.append(0)
        else:
            real.append(1)
        ones=z
    else:
        if v>prev+i-1-2*ones:
            real.append(0)
        else:
            real.append(1)
        ones=i-1-ones+(real[-1]-1)%2
    prev=v
x=real.count(1)
if x!=t:
    real.append(1)
else:
    real.append(0)
out=""
for i in range(n):
    out+=str(real[i])
print("!",out)