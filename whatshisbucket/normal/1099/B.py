n=int(input())
k=int(n**0.5)
if k**2==n:
    print(2*k)
elif n<=k**2+k:
    print(2*k+1)
else:
    print(2*k+2)