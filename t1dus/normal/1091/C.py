n = int(input())
a = set([])
i = 1
while i*i <= n:
    if(n%i == 0):
        x = i
        y = n//i
        # 1+x+1+2x+1+....+(y-1)x+1
        # y + (y)(y-1)(x)/2
        a.add(y+(((y)*(y-1)*(x))//2))
        x,y = y,x
        a.add(y+(((y)*(y-1)*(x))//2))
    i += 1
a = sorted(list(a))
for i in a:
    print(int(i),end=' ')
print()