print("? 1 2")
a=int(input())
print("? 2 3")
b=int(input())
print("? 4 5")
c=int(input())
print("? 5 6")
d=int(input())
arr=[4,8,15,16,23,42]
done=False
for a1 in range(6):
    for a2 in range(6):
        for a3 in range(6):
            for a4 in range(6):
                for a5 in range(6):
                    for a6 in range(6):
                        if len(set([a1,a2,a3,a4,a5,a6]))==6:
                            new=[arr[a1],arr[a2],arr[a3],arr[a4],arr[a5],arr[a6]]
                            #print(new)
                            #print(new[0]*new[1]==a,new[1]*new[2]==b,new[3]*new[4]==c,new[4]*new[5]==d)
                            if new[0]*new[1]==a and new[1]*new[2]==b and new[3]*new[4]==c and new[4]*new[5]==d:
                                new=[str(guy) for guy in new]
                                print("! "+" ".join(new))
                                done=True