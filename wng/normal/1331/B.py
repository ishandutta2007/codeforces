

r=""
s=int(input())
i=2
while (i<=s):
    while (s%i)==0:
        s//=i
        r+=str(i)
    i+=1
print(r)