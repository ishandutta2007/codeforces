n=int(input())
a=set(list(map(int,input().split()))[1:])
for i in range(n-1):
    a=a&set(list(map(int,input().split()))[1:])
out=""
for guy in a:
    out+=str(guy)+" "
print(out[:-1])