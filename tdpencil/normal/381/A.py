user = int(input())
lst = []
turns, score1, score2 = (0, 0, 0)

j = input()
nums = j.split()
for i in nums:
    lst.append(int(i))

while (user > 0):
    user-=1
    if turns % 2 == 1:
        rightIdx = lst[len(lst)-1]
        leftIdx = lst[0]
        if rightIdx > leftIdx:
            score2+=rightIdx
            lst.remove(rightIdx)
        elif leftIdx > rightIdx:
            score2+=leftIdx
            lst.remove(leftIdx)
        else:
            score2+=lst[0]
            lst = []
    else:
        rightIdx = lst[len(lst)-1]
        leftIdx = lst[0]
        if rightIdx > leftIdx:
            score1+=rightIdx
            lst.remove(rightIdx)
        elif leftIdx > rightIdx:
            score1+=leftIdx
            lst.remove(leftIdx)
        else:
            score1+=lst[0]
            lst = []
    turns+=1
print(score1, score2)