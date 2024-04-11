{$R-,S-,Q-,I-,O+}
var
  deg,x,cnt,ans,ss,ff,pred,last,c: array [0..500010] of longint;
  was: array [0..500010] of boolean;
  cur,n,m,i,ii,j,e,q: longint;

procedure go();
var
  i,id,r,cur: longint;
begin
  id:=1; cur:=0;
  for r:=1 to 2 do
    for i:=1 to n do
      if (c[i] = r) and (ans[i] = 0) then
      begin
        ans[i]:=id;
        inc(cur);
        if cur = 3 then
        begin
          inc(id);
          cur:=0;
        end;
      end;
  writeln('YES');
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
  halt;
end;

begin
  read(n,m);
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  for i:=1 to n do c[i]:=0;
  for ii:=1 to n do
    if c[ii] = 0 then
    begin
      i:=1; e:=1;
      x[1]:=ii;
      c[ii]:=1;
      while i <= e do
      begin
        j:=last[x[i]];
        while j > 0 do
        begin
          if c[ff[j]] = 0 then
          begin
            inc(e);
            x[e]:=ff[j];
            c[x[e]]:=3-c[x[i]];
          end;
          j:=pred[j];
        end;
        inc(i);
      end;
    end;
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to n do inc(cnt[c[i]]);
  for i:=1 to n do ans[i]:=0;
  if cnt[1] mod 3 = 0 then go() else
  begin
    if cnt[1] mod 3 = 2 then
    begin
      for i:=1 to n do c[i]:=3-c[i];
      j:=cnt[1]; cnt[1]:=cnt[2]; cnt[2]:=j;
    end;
    for i:=1 to m+m do inc(deg[ss[i]]);
    for i:=1 to n do
      if (c[i] = 1) and (deg[i] <= cnt[2]-2) then
      begin
        for j:=1 to n do was[j]:=(c[j] = 1);
        j:=last[i];
        while j > 0 do
        begin
          was[ff[j]]:=True;
          j:=pred[j];
        end;
        ans[i]:=n div 3;
        cur:=1;
        for j:=1 to n do
          if not was[j] then
          begin
            ans[j]:=n div 3;
            inc(cur);
            if cur = 3 then break;
          end;
        go();
      end;
    for i:=1 to n do
      if (c[i] = 2) and (deg[i] <= cnt[1]-2) then
      begin
        for j:=i+1 to n do
          if (c[j] = 2) and (deg[j] <= cnt[1]-2) then
          begin
            for q:=1 to n do was[q]:=(c[q] = 2);
            q:=last[i];
            while q > 0 do
            begin
              was[ff[q]]:=True;
              q:=pred[q];
            end;
            ans[i]:=n div 3;
            cur:=1;
            for q:=1 to n do
              if not was[q] then
              begin
                ans[q]:=n div 3;
                inc(cur);
                if cur = 3 then break;
              end;
            for q:=1 to n do was[q]:=(c[q] = 2);
            q:=last[j];
            while q > 0 do
            begin
              was[ff[q]]:=True;
              q:=pred[q];
            end;
            ans[j]:=n div 3-1;
            cur:=1;
            for q:=1 to n do
              if not was[q] then
              begin
                ans[q]:=n div 3-1;
                inc(cur);
                if cur = 3 then break;
              end;
            go();
          end;
        break;
      end;
    writeln('NO');
  end;
end.