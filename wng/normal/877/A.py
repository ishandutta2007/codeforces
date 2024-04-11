#[int(k) for k in raw_input().split(" ")]
import string
names= ["Danil", "Olya", "Slava", "Ann","Nikita"]
pb=raw_input()
lpb=len(pb)

tot=0
for k in names:
    l=len(k)
    tot+=(lpb-len(string.replace(pb,k,"")))/l
    
if tot==1:
    print "YES"
else:
    print "NO"