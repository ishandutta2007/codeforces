a1 = map(int,raw_input().split())
a2 = map(int,raw_input().split())
b1 = map(int,raw_input().split())
b2 = map(int,raw_input().split())

def win1(a1,a2,b1,b2):
	if a1[0] > b1[1] and a2[1] > b2[0] and a1[0] > b2[1] and a2[1] > b1[0]:
		return True
	if a2[0] > b1[1] and a1[1] > b2[0] and a2[0] > b2[1] and a1[1] > b1[0]:
		return True
	return False

def win2(a1,a2,b1,b2):
	if (a1[0] > b1[1] and a2[1] > b2[0] or a2[0] > b1[1] and a1[1] > b2[0]) and (a1[0] > b2[1] and a2[1] > b1[0] or a2[0] > b2[1] and a1[1] > b1[0]):
		return True
	return False

if win1(a1,a2,b1,b2):
	print "Team 1"
elif win2(b1,b2,a1,a2):
	print "Team 2"
else:
	print "Draw"