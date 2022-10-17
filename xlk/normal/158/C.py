s=[];
for i in range(input()):
	c=raw_input();
	if c>"p":print"/".join([""]+s+[""])
	else:
		for i in c[3:].split("/"):s=[s+[i],s[:-1],[]][(".">i)+("A">i)]