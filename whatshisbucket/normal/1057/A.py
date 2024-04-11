n=int(input())
a=list(map(int,input().split()))
vertex=n
guys=[]
while vertex>1:
    guys.append(vertex)
    vertex=a[vertex-2]
guys.append(1)
guys.reverse()
one=""
for i in guys:
    one+=(str(i)+" ")
print(one[:-1])