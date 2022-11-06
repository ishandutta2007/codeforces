a=raw_input()

p=0
l=0
for i in a:
    if i=="o":
        p+=1
    else:
        l+=1

if p==0 or not l%p:
    print "YES"
else:
    print "NO"