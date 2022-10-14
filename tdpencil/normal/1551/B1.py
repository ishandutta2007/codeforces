tt=int(input())
for j in range(tt):
    x=input()
    cnt = [0 for i in range(26)]
    for c in x:
        cnt[ord(c) - ord('a')] += 1
    left=0
    right=0
    for i in cnt:
        if i == 1:
            if left < right:
                left += 1
            else:
                right += 1
        elif i >= 2:
            left += 1
            right += 1
    print(min(left, right))