
#978c

n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]

ia=0
cde=0

for i in b:
    while cde+a[ia]<i:
        cde+=a[ia]
        ia+=1
    print ia+1,i-cde