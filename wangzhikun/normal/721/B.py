t=input()
n=int(t.split(' ')[0])
k=int(t.split(' ')[1])
l=[]
for i in range(n):
    l.append(input())
password = input()
t=0
l.sort(key=len)
for i in l:
    t+=1
    if len(i)==len(password):
        break
def getans(t):
    global k
    q=-1
    ans=0
    for i in range(t):
        q+=1
        ans+=1
        if q%k==0 and q>=k:
            ans+=5
    return ans
a=getans(t)
t=0
for i in l:
    if len(i)>len(password):
        break
    t+=1
b=getans(t)
print(a,b)