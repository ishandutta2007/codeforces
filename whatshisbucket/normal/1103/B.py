a=input()
while a!="end":
    if a=="start":
        for i in range(30):
            print("?",2**i,2*2**i)
            if input()=="x":
                break
        bot=2**i
        top=min(2**(i+1),1000000000)
        if bot==1:
            print("?",2,1)
            if input()=="x":
                print("!",1)
            else:
                print("!",2)
        else:
            bot+=1
            while top!=bot:
                mid=(bot+top)//2
                print("?",2*mid,mid)
                if input()=="x":
                    top=mid
                else:
                    bot=mid+1
            print("!",top)
    a=input()