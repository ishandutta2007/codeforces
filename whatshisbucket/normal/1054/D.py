n,k=map(int,input().split())
a=list(map(int,input().split()))
running=[0]
for i in range(n):
    running.append(running[-1]^a[i])
for i in range(n+1):
    if running[i]>=2**(k-1):
        running[i]=2**k-1-running[i]
running.sort()
streaks=[]
curr=1
for i in range(n):
    if running[i]==running[i+1]:
        curr+=1
    else:
        streaks.append(curr)
        curr=1
streaks.append(curr)
bad=0
for guy in streaks:
    if guy%2==0:
        bad+=(guy//2)*(guy//2-1)
    else:
        bad+=(guy//2)**2
print((n*(n+1))//2-bad)