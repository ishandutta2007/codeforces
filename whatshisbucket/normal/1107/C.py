n,k=map(int,input().split())
a=list(map(int,input().split()))
s=input()
start=0
intervals=[]
for i in range(n-1):
    if s[i]!=s[i+1]:
        intervals.append((start,i+1))
        start=i+1
intervals.append((start,n))
total=0
for interval in intervals:
    if interval[1]-interval[0]>k:
        remove=interval[1]-interval[0]-k
        order=sorted(a[interval[0]:interval[1]])
        total+=sum(order[:remove])
print(sum(a)-total)