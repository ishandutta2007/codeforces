import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class TreePainting {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }
        for (int i = 1; i < n; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            nodes[a].adjacent.add(nodes[b]);
            nodes[b].adjacent.add(nodes[a]);
        }
        Stack<Node> stack = new Stack<>();
        stack.push(nodes[1]);
        long curr = (long) n;
        long depth = 0;
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node.visited1) {
                depth--;
                if (node.parent != null) {
                    node.parent.subTreeSize += node.subTreeSize;
                }
            } else {
                curr += depth;
                node.visited1 = true;
                stack.push(node);
                for (Node child : node.adjacent) {
                    if (child == node.parent) {
                        continue;
                    }
                    child.parent = node;
                    stack.push(child);
                }
                depth++;
            }
        }
        long res = curr;
        for (Node child : nodes[1].adjacent) {
            stack.push(child);
        }
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node.visited2) {
                curr += node.subTreeSize;
                curr -= n - node.subTreeSize;
            } else {
                node.visited2 = true;
                curr -= node.subTreeSize;
                curr += n - node.subTreeSize;
                res = Math.max(res, curr);
                stack.push(node);
                for (Node child : node.adjacent) {
                    if (child == node.parent) {
                        continue;
                    }
                    stack.push(child);
                }
            }
        }
        System.out.println(res);
    }

    static class Node {
        final int ix;
        Node parent = null;
        final List<Node> adjacent = new ArrayList<>();
        long subTreeSize = 1;
        boolean visited1 = false;
        boolean visited2 = false;

        Node(int ix) {
            this.ix = ix;
        }
    }
}