s = input()
cur1 = 0
cur2 = 0
for i in range(len(s)):
    if s[i] == '0':
        cur1+=1
        print(1,cur1)
        cur1 %= 4
    else:
        cur2 += 1
        print(3,2*cur2-1)
        cur2 %= 2