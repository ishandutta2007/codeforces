n=int(input())
k=n//2+1
print(k)
for i in range(k):
    print(1,i+1)
for i in range(n-k):
    print(i+2,k)