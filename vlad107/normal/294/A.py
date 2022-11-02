R=lambda:map(int,raw_input().split())
n=int(input())
a=R()
m=int(input())
for _ in range(m):
    x,y=R()
    x-=1
    if (x>0):a[x-1]+=y-1
    if (x<n-1):a[x+1]+=a[x]-y
    a[x]=0
print '\n'.join(map(str,a))