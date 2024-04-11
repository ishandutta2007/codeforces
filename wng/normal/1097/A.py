a=[k for k in raw_input().split(" ")][0]
b=[k for k in raw_input().split(" ")]

isok=False
for i in b:
    if i[0]==a[0] or i[1]==a[1]:
        isok=True

if isok:
    print "YES"
else:
    print "NO"