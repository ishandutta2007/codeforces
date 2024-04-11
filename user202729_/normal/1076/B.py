n=int(input())
ans=0
if n%2!=0:
   i=3
   while n%i!=0 and i*i<n:i+=2
   if n%i!=0:i=n
   n-=i
   ans=1
ans+=n//2
print(ans)