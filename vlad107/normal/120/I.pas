var
  ka:array['0'..'9','0'..'9']of longint;
  s:ansistring;
  pc,c1,c2:char;
  cr,x,j,kr,i,n,sum:longint;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  readln(s);
  for c1:='0'to'9'do
    for c2:='0'to'9'do begin
      ka[c1][c2]:=0;
      if not ((c1 in ['1','4'])or(c2 in['1','4']))then inc(ka[c1][c2]);
      if not ((c1 in ['1','2','3','7'])or(c2 in['1','2','3','7']))then inc(ka[c1][c2]);
      if not ((c1 in ['5','6'])or(c2 in['5','6']))then inc(ka[c1][c2]);
      if not ((c1 in ['0','1','7'])or(c2 in['0','1','7']))then inc(ka[c1][c2]);
      if not ((c1 in ['1','3','4','5','7','9'])or(c2 in ['1','3','4','5','7','9']))then inc(ka[c1][c2]);
      if not ((c1 in ['2'])or(c2 in ['2']))then inc(ka[c1][c2]);
      if not ((c1 in ['1','4','7'])or(c2 in ['1','4','7']))then inc(ka[c1][c2]);
    end;

  n:=length(s)div 2;
  kr:=0;
  for i:=1 to n do
    inc(kr,ka[s[i],s[i+n]]);

  sum:=0;
  x:=0;
  for i:=1 to n do begin
    if (s[i]='9')then begin
      inc(sum,ka['9','8']);
      continue;
    end;
    cr:=sum+(n-i)*7;
    for c1:=chr(ord(s[i])+1)to '9'do begin
      if (cr+ka[c1,'8']>kr)then begin
        cr:=-1;
        break;
      end;
    end;
    if (cr<0)then x:=i;
    inc(sum,ka[s[i],'8']);
  end;
    for i:=n+1 to n+n do begin
      dec(sum,ka[s[i-n],'8']);
      if (s[i]='9')then begin
        inc(sum,ka[s[i-n],'9']);
        continue;
      end;
      cr:=sum;
      for c1:=chr(ord(s[i])+1)to '9'do begin
        if (cr+ka[c1,s[i-n]]>kr)then begin
          cr:=-1;
          break;
        end;
      end;
      if (cr<0)then begin
        x:=i;
      end;
      inc(sum,ka[s[i-n],s[i]]);
    end;
    if (x=0)then begin
      writeln(-1);
      exit;
    end;
    if (x>n)then begin
    sum:=0;
    for i:=1 to n do
      if (i+n<x)then inc(sum,ka[s[i],s[i+n]]) else
      if (i+n>x)then inc(sum,ka[s[i],'8']);

    for c1:=chr(ord(s[x])+1)to '9'do begin
      if (sum+ka[c1,s[x-n]]>kr)then begin
        s[x]:=c1;break;
      end;
    end;
    sum:=sum+ka[s[x],s[x-n]];

    for i:=x+1 to n+n do begin
      c1:='0';
      while (true)do begin
        cr:=sum-ka['8',s[i-n]]+ka[c1,s[i-n]];
        if (cr>kr)then begin
          s[i]:=c1;break;
        end;
        c1:=chr(ord(c1)+1);
      end;
      sum:=sum-ka[s[i-n],'8']+ka[s[i-n],s[i]];
    end;
    writeln(s);
    exit;
  end;
  while (x>0)and(s[x]='9')do dec(x);
  if (x=0)then begin
    writeln(-1);
    exit;
  end;
  sum:=0;
  for i:=1 to n do
    if (i<x)then inc(sum,ka[s[i],'8'])else
    if (i>x)then inc(sum,7);
  for c1:=chr(ord(s[x])+1)to '9'do begin
    if (sum+ka[c1,'8']>kr)then begin
      s[x]:=c1;break;
    end;
  end;
  sum:=sum+ka[s[x],'8'];
  for i:=x+1 to n+n do begin
    pc:='8';
    c1:='0';
    while (true)do begin
      if (i<=n)
        then cr:=sum-ka['8','8']+ka[c1,'8']
        else cr:=sum-ka['8',s[i-n]]+ka[c1,s[i-n]];
      if (cr>kr)then begin
        s[i]:=c1;break;
      end;
      c1:=chr(ord(c1)+1);
    end;
    if (i<=n)
      then sum:=sum-ka[pc,'8']+ka[s[i],'8']
      else sum:=sum-ka[pc,s[i-n]]+ka[s[i],s[i-n]];
  end;
  writeln(s);
  close(output);close(input);
end.