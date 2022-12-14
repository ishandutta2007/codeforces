import sys
sys.stdin.readline()
ans=''
stk=[1]
for word in sys.stdin.readline().strip().split(' '):
	if not stk:
		stk=1
		break
	stk[-1]-=1
	ans+=','+word
	if word[0]=='p':
		stk.append(2)
		ans+='<'
	while stk and stk[-1]==0:
		stk.pop()
		ans+='>'
if stk:
	print('Error occurred')
else:
	print(ans.replace('<,','<')[1:-1])