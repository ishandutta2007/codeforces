
def proc(a,b):
    if a*b==0:
        return a,b
    else:
        if a>=2*b:
            return proc(a%(2*b),b)
        elif b>=2*a:
            return proc(a,b%(2*a))
        else:
            return a,b
        
a,b=[int(k) for k in raw_input().split(" ")]

a,b=proc(a,b)
print a,b