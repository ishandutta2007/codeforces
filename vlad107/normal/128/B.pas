var
  oo,k,kt,kt2,n,i,j:longint;
  kq:array[#0..#255]of int64;
  t,t2:array[0..500500]of longint;
  sum:int64;
  ch:char;
  s:ansistring;

begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(s);
  readln(k);
  n:=length(s);
  sum:=int64(n+1)*n div 2;
  if (sum<k)then begin
    writeln('No such line.');
    close(output);close(input);
    halt(0);
  end;
  for i:=1 to n do t[i]:=i;
  kt:=n;
  while (k>0)do begin
    fillchar(kq,sizeof(kq),$0);
    for i:=1 to kt do kq[s[t[i]]]:=kq[s[t[i]]]+n-t[i]+1;
    ch:=#0;
    while (kq[ch]<k)do begin
      dec(k,kq[ch]);
      ch:=chr(ord(ch)+1);
    end;
    write(ch);
    oo:=0;
    for i:=1 to kt do
      if (s[t[i]]=ch)then inc(oo);
    if (k<=oo)then break;
    dec(k,oo);
    kt2:=0;
    for i:=1 to kt do
      if (s[t[i]]=ch)and(t[i]<n)then begin
        inc(kt2);
        t2[kt2]:=t[i]+1;
      end;
    kt:=kt2;
    for i:=1 to kt do t[i]:=t2[i];
  end;
  close(output);close(input);
end.