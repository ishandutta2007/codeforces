n=int(input())

vs="aeiou"

def res(rs,c):
    r=[]
    for i in range(rs):
        for j in range(c):
            r+=[vs[(i-j)%5]]
    return "".join(r)

for i in range(5,n//5+1):
    if not n%i:
        ot=n//i
        if ot>=5:
            print(res(i,ot))
            exit(0)

print("-1")