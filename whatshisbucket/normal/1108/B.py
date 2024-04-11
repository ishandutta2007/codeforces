n=int(input())
d=list(map(int,input().split()))
d.sort()
big=d[-1]
facs=[]
bigfacs=[]
for i in range(1,int(big**0.5)+1):
    if big%i==0:
        facs.append(i)
        bigfacs.append(big//i)
if bigfacs[-1]==facs[-1]:
    bigfacs.pop()
facs+=bigfacs[::-1]
ind=0
facind=0
while facind<len(facs):
    if facs[facind]==d[ind]:
        d.pop(ind)
        facind+=1
    else:
        ind+=1
print(big,d[-1])