from fractions import gcd

n = int(input())
a = list(map(int,input().split()))

ans = a[0]
for i in a:
    ans = gcd(ans,i)

cnt = max(a)//ans
left = cnt-n

if left%2 == 1:
    print("Alice")
    
else:
    print("Bob")