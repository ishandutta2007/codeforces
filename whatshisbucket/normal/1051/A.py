t=int(input())
for u in range(t):
    s=input()
    alph="abcdefghijklmnopqrstuvwxyz"
    ALPH="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    num="1234567890"
    counts=[0,0,0]
    for char in s:
        if char in alph:
            counts[0]+=1
        elif char in num:
            counts[2]+=1
        else:
            counts[1]+=1
    if counts[0]>0 and counts[1]>0 and counts[2]>0:
        print(s)
    else:
        if counts[0]==counts[1]==0:
            print("aA"+s[2:])
        elif counts[0]==counts[2]==0:
            print("a1"+s[2:])
        elif counts[1]==counts[2]==0:
            print("A1"+s[2:])
        elif counts[0]==0:
            if counts[1]>1:
                for i in range(len(s)):
                    if s[i] in ALPH:
                        print(s[:i]+"a"+s[i+1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in num:
                        print(s[:i]+"a"+s[i+1:])
                        break
        elif counts[1]==0:
            if counts[0]>1:
                for i in range(len(s)):
                    if s[i] in alph:
                        print(s[:i]+"A"+s[i+1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in num:
                        print(s[:i]+"A"+s[i+1:])
                        break
        else:
            if counts[0]>1:
                for i in range(len(s)):
                    if s[i] in alph:
                        print(s[:i]+"1"+s[i+1:])
                        break
            else:
                for i in range(len(s)):
                    if s[i] in ALPH:
                        print(s[:i]+"1"+s[i+1:])
                        break