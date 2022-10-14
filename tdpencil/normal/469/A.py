n=int(input())
lst = [int(i) for i in range(1, n+1)]
j = [int(i) for i in input().split()]
b= [int(i) for i in input().split()]
ok =False
j[0]=0
b[0]=0
for i in j:
    if i in lst:
        lst.remove(i)
for l in b:
    if l in lst:
        lst.remove(l)
if lst==[]:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")