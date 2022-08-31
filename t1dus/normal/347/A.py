n = int(input())
a = list(map(int,input().split()))
a.sort(reverse = True)
b = a[::]
a.pop(0)
a.pop()
a.sort()
print(b[0],end = ' ')
for i in a:
    print(i,end = ' ')
print(b[-1])