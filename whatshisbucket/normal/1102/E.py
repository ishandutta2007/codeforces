n=int(input())
a=list(map(int,input().split()))
intervals={}
for i in range(n):
    if a[i] in intervals:
        intervals[a[i]][1]=i
    else:
        intervals[a[i]]=[i,i]
new=[intervals[guy] for guy in intervals]
new.sort()
power=new[0][0]
long=new[0][1]
for i in range(len(new)-1):
    if new[i+1][0]<=long:
        long=max(long,new[i+1][1])
    else:
        power+=new[i+1][0]-long
        long=new[i+1][1]
power+=n-1-long
prod=1
for i in range(power):
    prod*=2
    prod%=998244353
print(prod)