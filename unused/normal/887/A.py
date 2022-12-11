a=raw_input()
cnt=-1
for i in a:
    if cnt == -1:
        if i == '1':
            cnt = 0
    elif i == '0':
        cnt += 1
if cnt >= 6:
    print 'yes'
else:
    print 'no'