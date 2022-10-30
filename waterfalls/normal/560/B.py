[A,B] = map(int,input().split())
A,B = A+1,B+1
[a,b] = map(int,input().split())
[c,d] = map(int,input().split())
found = 0
for i in range(2):
    for j in range(2):
        if (a+c<A and b<B and d<B) or (b+d<B and a<A and c<A):
            found = 1
        a,b = b,a
    c,d = d,c
print("YES" if found else "NO")