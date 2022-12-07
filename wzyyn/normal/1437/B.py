T=int(input())

def Abs(x):
    if x<0:
        return -x
    return x
for Tid in range(T):
    n=int(input())
    s=input()
    sum0,sum1=0,0
    for i in range(1,n):
        if s[i]=='0' and s[i-1]=='0':
            sum0=sum0+1
        if s[i]=='1' and s[i-1]=='1':
            sum1=sum1+1
    print(max(sum0,sum1))