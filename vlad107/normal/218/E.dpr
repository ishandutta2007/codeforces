var
  s:ansistring;
  kg,st1,sl,sr,st,nom:array[0..1000500]of longint;
  g:array[0..1000000,0..3]of longint;
  f0,f1,kst,kq,xx,yy,kst1,kst2,n,i:longint;
  ty,st2:array[0..1000500]of char;
  f:array[0..1000000,0..1,0..1]of longint;

  function calc(x,y:longint;t:char):longint;
    begin
      if (t='|')then calc:=x or y else
      if (t='&')then calc:=x and y else
      if (t='^')then calc:=x xor y;
    end;
    
  function rec(t,x,y:longint):boolean;
    var
      x1,y1,x2,y2:longint;
      
    begin
      if (f[t][x][y]<>-1)then begin
        if (f[t][x][y]=1)then rec:=true else rec:=false;
        exit;
      end;
      if (s[sl[t]]<>'(')then begin
        if (s[sl[t]]='?')then begin
          f[t][0][1]:=1;
          f[t][1][0]:=1;
        end else begin
          x1:=ord(s[sl[t]])-48;
          f[t][x1][x1]:=1;
        end;
        if (f[t][x][y]<>1)then f[t][x][y]:=0;
        rec:=f[t][x][y]=1;
        exit;
      end;
      for x1:=0 to 1 do
        for y1:=0 to 1 do f[t][x1][y1]:=0;
      f[t][x][y]:=0;
      for x1:=0 to 1 do 
        for y1:=0 to 1 do 
          for x2:=0 to 1 do 
            for y2:=0 to 1 do 
              if (rec(g[t][1],x1,y1))and(rec(g[t][2],x2,y2))
                then f[t][calc(x1,x2,ty[t])][calc(y1,y2,ty[t])]:=1;
      rec:=f[t][x][y]=1;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(n);
  readln(s);
  for i:=1 to length(s)do begin
    if (s[i]='(')or(s[i]in['0','1','?'])then begin
      inc(kq);
      inc(kst);
      st[kst]:=i+1;
      nom[kst]:=kq;
      sl[kq]:=i;
    end;
    if (s[i]=')')or(s[i]in['0','1','?'])then begin
      yy:=nom[kst];
      sr[nom[kst]]:=i;
      dec(kst);
      xx:=nom[kst];
      inc(kg[xx]);
      g[xx][kg[xx]]:=yy;
    end;
    if (s[i] in ['&','|','^'])then ty[nom[kst]]:=s[i];
  end;
  fillchar(f,sizeof(f),$FF);
  if (rec(1,0,1))then begin
    writeln('YES');
    exit;
  end;
  writeln('NO');
end.