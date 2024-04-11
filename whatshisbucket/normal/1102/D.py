n=int(input())
s=input()
lists=[int(char) for char in s]
a,b=s.count("0"),s.count("1")
c=n-a-b
a,b,c=n//3-a,n//3-b,n//3-c
if a>0:
    for i in range(n):
        if a==0:
            break
        if lists[i]==1:
            if b<0:
                lists[i]=0
                b+=1
                a-=1
        elif lists[i]==2:
            if c<0:
                lists[i]=0
                c+=1
                a-=1
if b>0 and c<0:
    for i in range(n):
        if b==0 or c==0:
            break
        if lists[i]==2:
            lists[i]=1
            b-=1
            c+=1
if a<0:
    for i in range(n):
        if a==0:
            break
        if lists[-i-1]==0:
            if c>0:
                lists[-i-1]=2
                c-=1
                a+=1
            else:
                lists[-i-1]=1
                b-=1
                a+=1
if b<0:
    for i in range(n):
        if b==0:
            break
        if lists[-i-1]==1:
            lists[-i-1]=2
            b+=1
            c-=1
lists=[str(lists[i]) for i in range(n)]
print("".join(lists))