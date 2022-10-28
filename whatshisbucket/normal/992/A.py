a=int(input())
distinct=set()
b=list(map(int,input().split()))
for i in range(a):
    distinct.add(b[i])
if 0 in distinct:
    distinct.remove(0)
print(len(distinct))