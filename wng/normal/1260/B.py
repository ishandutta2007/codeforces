
t=int(input())
for nt in range(t):
    a,b=[int(k) for k in input().strip().split(" ")]
    if (a+b)%3 or 2*a<b or 2*b<a:
        print("NO")
    else:
        print("YES")