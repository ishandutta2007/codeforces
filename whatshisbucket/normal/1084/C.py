s=input()
n=len(s)
a=[]
curr=0
for i in range(n):
    if s[i]=="a":
        curr+=1
    elif s[i]=="b":
        a.append(curr)
        curr=0
if curr>0:
    a.append(curr)
prod=1
for i in range(len(a)):
    prod*=(a[i]+1)
    prod=prod%1000000007
print(prod-1)