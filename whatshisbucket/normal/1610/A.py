for _ in range(int(input())):
	s=set(input().split());print(0 if s=={'1'} else 1 if '1' in s else 2)