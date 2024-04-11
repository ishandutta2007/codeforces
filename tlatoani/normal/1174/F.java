import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class BigFinale {
    static final Scanner scanner = new Scanner(System.in);
    static final Node[] nodes = new Node[200001];

    public static void main(String[] args) {
        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }
        for (int j = 1; j < n; j++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            nodes[a].children.add(nodes[b]);
            nodes[b].children.add(nodes[a]);
        }
        nodes[1].depth = 0;
        Stack<Node> stack = new Stack<>();
        stack.push(nodes[1]);
        while (!stack.isEmpty()) {
            Node node = stack.pop();
            if (node.seen) {
                node.subTreeSize = 1;
                for (Node child : node.children) {
                    if (node.parent != child) {
                        node.subTreeSize += child.subTreeSize;
                        if (node.bestChild == null || child.subTreeSize > node.bestChild.subTreeSize) {
                            node.bestChild = child;
                            node.bestDescendant = child.bestDescendant;
                        }
                    }
                }
                if (node.bestDescendant == null) {
                    node.bestDescendant = node;
                }
                /*if (node.bestChild != null) {
                    System.out.println("nodes[" + node.ix + "].bestChild = nodes[" + node.bestChild.ix + "]");
                } else {
                    System.out.println("nodes[" + node.ix + "].bestChild = null");
                }
                System.out.println("nodes[" + node.ix + "].bestDescendant = nodes[" + node.bestDescendant.ix + "]");*/
            } else {
                node.seen = true;
                stack.push(node);
                for (Node child : node.children) {
                    if (node.parent != child) {
                        child.parent = node;
                        child.depth = node.depth + 1;
                        stack.push(child);
                    }
                }
            }
        }
        int xDepth = xDist(nodes[1]);
        Node node = nodes[1];
        while (node.depth != xDepth) {
            int descDist = xDist(node.bestDescendant);
            int peakDepth = (xDepth + node.bestDescendant.depth - descDist) >> 1;
            for (; node.depth < peakDepth; node = node.bestChild);
            if (node.depth == xDepth) {
                break;
            }
            node = nextChild(node);
        }
        System.out.println("! " + node.ix);
    }

    static int xDist(Node node) {
        System.out.println("d " + node.ix);
        int res = scanner.nextInt();
        if (res == -1) {
            System.exit(0);
        }
        return res;
    }

    static Node nextChild(Node node) {
        System.out.println("s " + node.ix);
        int res = scanner.nextInt();
        if (res == -1) {
            System.exit(0);
        }
        return nodes[res];
    }

    static class Node {
        final int ix;
        int depth = -1;
        Node parent = null;
        boolean seen = false;
        List<Node> children = new ArrayList<>();
        int subTreeSize = -1;
        Node bestChild = null;
        Node bestDescendant = null;

        Node(int ix) {
            this.ix = ix;
        }
    }
}