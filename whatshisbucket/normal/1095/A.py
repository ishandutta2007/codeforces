n=int(input())
s=input()
inverse={1:1,3:2,6:3,10:4,15:5,21:6,28:7,36:8,45:9,55:10}
out=""
seen=0
for i in range(inverse[n]):
    out+=s[seen]
    seen+=i+1
print(out)