const
  inf=1000000000;

var
  cr,i,ans:longint;
  ff,u,ch:char;
  kol:array[0..500500,'A'..'Z']of longint;
  kc:array['A'..'Z']of longint;
  s,p:ansistring;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(s);
  readln(p);
  for i:=length(s)downto 1 do begin
    for  ch:='A' to 'Z' do kol[i][ch]:=kol[i+1][ch];
    inc(kol[i][s[i]]);
  end;
  for i:=1 to length(s)do dec(kc[s[i]]);
  for i:=1 to length(p)do inc(kc[p[i]]);
  ans:=0;
  for ch:='A' to 'Z' do inc(ans,abs(kc[ch]));
  writeln(ans shr 1);
  for i:=1 to length(s)do begin
    if (kc[s[i]]>=0)then continue;
    ff:=s[i];
    if (-kc[s[i]]=kol[i][s[i]])then ff:='Z';
    for ch:='A' to ff do 
      if (kc[ch]>0)then begin
        dec(kc[ch]);
        inc(kc[s[i]]);
        u:=ch;
        s[i]:=ch;
        break;
      end;
  end;
  writeln(s);
end.