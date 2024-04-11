n, k = map(int, input().split())
a = input()
d = a[0:k]
c = int(d)
b=d*(n//k)
print(n)
b+=d[0:n%k]
if(b>=a):
    print(b)
else:
    c+=1
    d=str(c)
    b=d*(n//k)
    b+=d[0:n%k]
    print(b)