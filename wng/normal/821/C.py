n=int(raw_input())
done=0
res=0
stack=[0]*300000
ssize=0

while done<n:
    ins=raw_input()
    #print ins
    if ins=="remove":
        if ssize>0 and stack[ssize-1]!=done+1:
         #  print stack
      #      stack=sorted(stack,reverse=True)
            ssize=0
     #       print "REORDER {}".format(stack)
            res+=1
        if ssize>0:
            ssize-=1
        done+=1
    if ins[:3]=="add":
        nb=int(ins[4:])
        stack[ssize]=nb
        ssize+=1
        

print res