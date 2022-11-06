raw_input()
a=sum([int(k) for k in raw_input().split(" ")])
b=sum([int(k) for k in raw_input().split(" ")])
if a>=b:
    print("Yes")
else:
    print "No"