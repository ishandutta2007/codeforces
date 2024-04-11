module main;

import core.stdc.stdio;

int main(string[] arv) {
	int n;
	scanf("%d", &n);
	char [] s = new char[n];
	for(int i = 0; i < n; i++) scanf(" %c", &s[i]);
	for(int i = 0; i < n; i++) {
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y')
			printf("%c", s[i]);
		else {
			int count = 1;
			for(int j = i + 1; j < n && s[i] == s[j]; j++) count++;
			if((s[i] == 'e' || s[i] == 'o') && count == 2)
				printf("%c%c", s[i], s[i]);
			else
				printf("%c", s[i]);
			while(s[i] == s[i+1]) i++;
		}
	}
	printf("\n");
	return 0;
}