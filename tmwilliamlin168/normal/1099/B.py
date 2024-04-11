ans=10**9
n=int(input())
i=1
while i*i<=n:
    ans=min(ans, i+(n-1)//i+1)
    i+=1
print(ans)