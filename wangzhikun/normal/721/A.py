length=int(input())
string=input()
ans = []
t=0
for i in range(length):
    if string[i]=="B":
        t+=1
    else:
        if t!=0:
            ans.append(t)
        t=0
if t!=0:
    ans.append(t)
print(len(ans))
for i in ans:
    print(i,end = " ")