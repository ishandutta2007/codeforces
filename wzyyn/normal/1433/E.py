n=int(input())
ans=1
for i in range(n//2):
    ans=ans*(n-i-1)//(i+1)
for i in range(1,n//2):
    ans=ans*i*i
print(ans)