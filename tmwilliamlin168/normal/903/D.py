n=int(input())
cnt={}
ans=0
allsum=0
v=list(map(int,input().split()))
for i in range(n):
    x=v[i]
    ans+=(i-cnt.get(x,0)-cnt.get(x-1,0)-cnt.get(x+1,0))*x-(allsum-cnt.get(x,0)*x-cnt.get(x-1,0)*(x-1)-cnt.get(x+1,0)*(x+1))
    cnt[x]=cnt.get(x,0)+1
    allsum+=x
print(ans)