n,m = map(int,input().split())
a = []
while n:
    a.append(n%m)
    n //= m
if(len(set(a)) == len(a)): print("YES")
else: print("NO")